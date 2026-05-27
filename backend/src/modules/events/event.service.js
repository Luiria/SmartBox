import { mapAdafruitToEvent } from "./event.mapper.js";

export default class EventService {

    constructor(client, repository) {
        this.client = client;
        this.repository = repository;
    }

    async syncEvent() {

        console.log("[EventService] syncEvent started");

        const rawEvents = await this.client.getLatest(10);
        console.log(`[EventService] ${rawEvents.length} events fetched`);

        const events = rawEvents.map(mapAdafruitToEvent);

        for (const event of events) {

            try {

                const exists = await this.repository.findEvent(event.id);

                if (exists) {
                    console.log(`[EventService] skip event ${event.id} (already exists)`);
                    continue;
                }

                await this.repository.saveEvent(event);
                console.log(`[EventService] saved event ${event.id}`);

            } catch (error) {

                console.error("[EventService] error processing event:", {
                    eventId: event.id,
                    message: error.message
                });

                throw error;
            }
        }

        console.log("[EventService] syncEvent completed");

    }

}


