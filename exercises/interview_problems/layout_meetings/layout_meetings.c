#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Box {
  float x;
  float y;
  float width;
  float height;
};

struct Boxes {
  struct Box const* const buffer;
  size_t const count;
};

struct Event {
  time_t start;
  time_t end;
};

struct Events {
  struct Event const* const buffer;
  size_t const count;
};

static bool events_overlap(struct Event a, struct Event b) {
  // a.start before b.end AND a.end after b.start
  return a.start < b.end && a.end > b.start;
}

static struct Boxes event_boxes(struct Box* boxes_buffer, struct Events events, float container_width) {
  // TODO: Sort events.buffer by event.start!
  float earliest_start_time = 0;
  if (events.count > 0) {
    earliest_start_time = events.buffer[0].start;
  }
  size_t i = 0;
  while (i < events.count) {
    size_t j = i;
    while (j + 1 < events.count) {
      struct Event curr_event = events.buffer[j];
      struct Event next_event = events.buffer[j + 1];
      if (!events_overlap(curr_event, next_event)) {
        break;
      }
      j++;
    }
    if (j > i) {
      size_t overlapping_events_count = (j - i) + 1;
      float width = container_width / overlapping_events_count;
      for (size_t k = 0; k < overlapping_events_count; k++) {
        struct Event event = events.buffer[i];
        float x = k * width;
        float y = event.start - earliest_start_time;
        float height = event.end - event.start;
        boxes_buffer[i] = (struct Box){ .x = x,
                                        .y = y,
                                        .width = width,
                                        .height = height };
        i++;
      }
    } else {
      struct Event event = events.buffer[i];
      float x = 0;
      float y = event.start - earliest_start_time;
      float width = container_width;
      float height = event.end - event.start;
      boxes_buffer[i] = (struct Box){ .x = x,
                                      .y = y,
                                      .width = width,
                                      .height = height };
      i++;
    }
  }
  return (struct Boxes){ .buffer = boxes_buffer, .count = events.count };
}

static void print_boxes(struct Boxes boxes) {
  for (size_t i = 0; i < boxes.count; i++) {
    struct Box box = boxes.buffer[i];
    printf("Box { .x = %f, .y = %f, .width = %f, .height = %f }\n",
           box.x,
           box.y,
           box.width,
           box.height);
  }
}

int main() {
  struct Event* events_buffer = calloc(5, sizeof(struct Event));
  events_buffer[0] = (struct Event){ .start = 0, .end = 60 };
  events_buffer[1] = (struct Event){ .start = 60, .end = 90 };
  events_buffer[2] = (struct Event){ .start = 70, .end = 120 };
  events_buffer[3] = (struct Event){ .start = 100, .end = 120 };
  events_buffer[4] = (struct Event){ .start = 120, .end = 150 };
  struct Events events = { .buffer = events_buffer, .count = 5 };
  struct Box* boxes_buffer = calloc(5, sizeof(struct Box));
  struct Boxes boxes = event_boxes(boxes_buffer, events, 100);
  print_boxes(boxes);
  free(events_buffer);
  free(boxes_buffer);
  return 0;
}
