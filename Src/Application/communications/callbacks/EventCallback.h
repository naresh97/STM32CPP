//
// Created by naresh on 28/05/22.
//

#ifndef HELLONUCLEO_EVENTCALLBACK_H
#define HELLONUCLEO_EVENTCALLBACK_H

#include <functional>
#include <memory>

template <typename T> class EventCallback {
private:
  std::shared_ptr<std::vector<std::function<void(T)>>> SubscribingFunctions;
  std::vector<int> SubscribedIndexes;

public:
  explicit EventCallback();
  EventCallback(const EventCallback &eventCallback);
  ~EventCallback();
  void DisposeFunction(int functionIndex);
  void PushMessage(T message);
  void Subscribe(std::function<void(T)> subscribeFunction);
};

template <typename T> EventCallback<T>::EventCallback() {
  SubscribingFunctions =
      std::make_shared<std::vector<std::function<void(T)>>>();
}

template <typename T>
void EventCallback<T>::DisposeFunction(int functionIndex) {
  SubscribingFunctions->operator[](functionIndex) = [](T) {};
}

template <typename T> void EventCallback<T>::PushMessage(T message) {
  if (SubscribingFunctions->empty())
    return;
  for (std::function<void(T)> fn : *SubscribingFunctions) {
    fn(message);
  }
}
template <typename T>
EventCallback<T>::EventCallback(const EventCallback &eventCallback) {
  this->SubscribingFunctions = eventCallback.SubscribingFunctions;
  this->SubscribedIndexes = std::vector<int>{};
}

template <typename T>
void EventCallback<T>::Subscribe(std::function<void(T)> subscribeFunction) {
  SubscribingFunctions->push_back(subscribeFunction);
  SubscribedIndexes.push_back(SubscribingFunctions->size() - 1);
}

template <typename T> EventCallback<T>::~EventCallback() {
  for (auto x : SubscribedIndexes) {
    DisposeFunction(x);
  }
}

#endif // HELLONUCLEO_EVENTCALLBACK_H
