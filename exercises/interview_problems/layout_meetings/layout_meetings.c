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
  time_t const start;
  time_t const end;
};

struct Events {
  struct Event const* const buffer;
  size_t const count;
};

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
  struct Events events = { .buffer = events_buffer, .count = 5 };
  struct Box* boxes_buffer = calloc(5, sizeof(struct Box));
  struct Boxes boxes = event_boxes(boxes_buffer, events);
  print_boxes(boxes);
  free(events_buffer);
  free(boxes_buffer);
  return 0;
}
