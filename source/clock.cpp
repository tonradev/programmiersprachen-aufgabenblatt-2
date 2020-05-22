#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include "mat2.hpp"
#include "rect.hpp"
#include "circle.hpp"
#include <iostream>

void update_hand(Vec2 & hand_outer, Vec2 const& clock_center) {
                hand_outer-=clock_center;
                hand_outer = (make_rotation_mat2(((360/60)*M_PI/180))*hand_outer);
                hand_outer+=clock_center;
}

int main(int argc, char* argv[])
{

  Window win{std::make_pair(800,800)};

    float last_time_seconds = 0.0f;
    float last_time_minutes = 0.0f;
    float last_time_hours = 0.0f;
    float now = win.get_time();
    Vec2 hand_inner{400.0f,365.0f};
    float clock_radius = 300.0f;
    Vec2 seconds_hand_outer{hand_inner.x,hand_inner.y-clock_radius};
    Vec2 minutes_hand_outer{hand_inner.x,hand_inner.y-clock_radius};
    Vec2 hours_hand_outer{hand_inner.x,hand_inner.y-(clock_radius/2)};

    Vec2 clock_center{400.0f, 365.0f};

    Circle c1{{400.0f,365.0f}, clock_radius, {0.4,0.1,0.8}};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    auto t = win.get_time();

    int text_offset_x = 10;
    int text_offset_y = 5;
    unsigned int font_size = 35;
    
    win.draw_text(text_offset_x, text_offset_y, font_size, std::to_string(t));

    c1.draw(win, 5.0f);

    now = win.get_time();

    if (now - last_time_seconds >= 1.0f) {
        last_time_seconds = int(now);
        update_hand(seconds_hand_outer, clock_center);
    }

    win.draw_line(hand_inner.x, hand_inner.y, seconds_hand_outer.x, seconds_hand_outer.y, 1.0f, 0.0f, 0.0f);

    if (now - last_time_minutes >= 60.0f) {
        last_time_minutes = int(now);
        update_hand(minutes_hand_outer, clock_center);
    }

    win.draw_line(hand_inner.x, hand_inner.y, minutes_hand_outer.x, minutes_hand_outer.y, 1.0f, 1.0f, 1.0f);

    if (now - last_time_hours >= 3600.0f) {
        last_time_hours = int(now);
        update_hand(hours_hand_outer, clock_center);
    }

    win.draw_line(hand_inner.x, hand_inner.y, hours_hand_outer.x, hours_hand_outer.y, 1.0f, 1.0f, 1.0f, 2.5f);


    win.update();
  }

  return 0;
}
