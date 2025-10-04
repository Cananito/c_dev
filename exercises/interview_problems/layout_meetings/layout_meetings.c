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

static int compare_events(const void* a, const void* b) {
  struct Event event_a = *((struct Event*)a);
  struct Event event_b = *((struct Event*)b);
  // Sorts in chronological order.
  return event_a.start > event_b.start;
}

static void copy_events_buffer(struct Event* dest,
                               struct Event const* src,
                               size_t count) {
  for (size_t i = 0; i < count; i++) {
    dest[i] = src[i];
  }
}

static struct Boxes event_boxes(struct Box* boxes_buffer,
                                struct Events events,
                                float container_width) {
  // Sort events by start time.
  struct Event* sorted_events_buffer = calloc(5, sizeof(struct Event));
  copy_events_buffer(sorted_events_buffer, events.buffer, events.count);
  qsort(sorted_events_buffer,
        events.count,
        sizeof(struct Event),
        compare_events);

  // Store earliest start time to later compute relative y's.
  float earliest_start_time = 0;
  if (events.count > 0) {
    earliest_start_time = sorted_events_buffer[0].start;
  }

  // Loop over the sorted events.
  size_t i = 0;
  while (i < events.count) {
    // Inner loop to gather the next group of overlapping events.
    size_t j = i;
    while (j + 1 < events.count) {
      struct Event curr_event = sorted_events_buffer[j];
      struct Event next_event = sorted_events_buffer[j + 1];
      if (!events_overlap(curr_event, next_event)) {
        break;
      }
      j++;
    }

    // If there are overlapping events, process those in another inner loop.
    if (j > i) {
      size_t overlapping_events_count = (j - i) + 1;
      float overlapping_event_with = container_width / overlapping_events_count;
      for (size_t k = 0; k < overlapping_events_count; k++) {
        struct Event event = sorted_events_buffer[i];
        float x = k * overlapping_event_with;
        float y = event.start - earliest_start_time;
        float height = event.end - event.start;
        boxes_buffer[i] = (struct Box){ .x = x,
                                        .y = y,
                                        .width = overlapping_event_with,
                                        .height = height };
        i++;
      }
    } else { // Otehrwise process the single next event.
      struct Event event = sorted_events_buffer[i];
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
  free(sorted_events_buffer);
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
  // Creating events in chronological order to more easily visualize them, but
  // appending them unsorted to verify event_boxes()'s sorting functionality.
  events_buffer[0] = (struct Event){ .start = 0, .end = 60 };
  events_buffer[2] = (struct Event){ .start = 60, .end = 90 };
  events_buffer[4] = (struct Event){ .start = 70, .end = 120 };
  events_buffer[1] = (struct Event){ .start = 100, .end = 120 };
  events_buffer[3] = (struct Event){ .start = 120, .end = 150 };
  struct Events events = { .buffer = events_buffer, .count = 5 };
  struct Box* boxes_buffer = calloc(5, sizeof(struct Box));
  struct Boxes boxes = event_boxes(boxes_buffer, events, 100);
  print_boxes(boxes);
  free(events_buffer);
  free(boxes_buffer);
  return 0;
}
