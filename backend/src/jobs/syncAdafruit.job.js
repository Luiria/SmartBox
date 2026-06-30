import { service } from "../modules/events/event.module.js";

let running = false;

export function startSyncJob() {
    setInterval(async () => {
        if (running) return;

        running = true;

        try {
            console.log("[SYNC] start");
            await service.syncEvent();
            console.log("[SYNC] done");
        } catch (e) {
            console.error("[SYNC] error", e.message);
        } finally {
            running = false;
        }

    }, 60000);
}