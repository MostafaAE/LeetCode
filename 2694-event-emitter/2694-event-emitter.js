class EventEmitter {
  events = new Map();
  id = 0;
  subscribe(event, cb) {
    const eventId = this.id++;
    this.events.set(eventId, { event, cb });
    return {
      unsubscribe: () => {
        this.events.delete(eventId);
      },
    };
  }

  emit(event, args = []) {
    return Array.from(this.events.values()).reduce((calls, entry) => {
      if (entry.event === event) calls.push(entry.cb(...args));
      return calls;
    }, []);
  }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */