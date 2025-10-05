#pragma once
#include "esphome/core/log.h"
#include "esphome/components/cover/cover.h"


template<typename T>
inline void log_cover_operation(T *cover_entity, const char *tag = "cover") {
  auto op = cover_entity->current_operation;
  const char *op_str = ::esphome::cover::cover_operation_to_str(op);
  float pos = cover_entity->position * 100.0f;
  ESP_LOGI(tag, "Operation: %s | Position: %.0f%%", op_str, pos);
}
