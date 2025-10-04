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

static struct Boxes event_boxes(struct Box* boxes_buffer, struct Events events) {
  // TODO: Implement algorithm!
  for (size_t i = 0; i < events.count; i++) {
    boxes_buffer[i] = (struct Box){ .x = 0,
                                    .y = i * 100,
                                    .width = 100,
                                    .height = 100 };
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
  events_buffer[2] = (struct Event){ .start = 70, .end = 100 };
  events_buffer[3] = (struct Event){ .start = 90, .end = 120 };
  events_buffer[4] = (struct Event){ .start = 120, .end = 150 };
  struct Events events = { .buffer = events_buffer, .count = 5 };
  struct Box* boxes_buffer = calloc(5, sizeof(struct Box));
  struct Boxes boxes = event_boxes(boxes_buffer, events);
  print_boxes(boxes);
  free(events_buffer);
  free(boxes_buffer);
  return 0;
}
