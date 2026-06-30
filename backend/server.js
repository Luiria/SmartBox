import { env } from "./src/config/env.js";
import { testConnection } from "./src/config/db.js";
import app from "./app.js";

await testConnection();

const PORT = env.PORT || 3000;

app.listen(PORT, () => {
    console.log(`Serveur démarré sur le port ${PORT}...`);
});

// import cron from "node-cron";
import { service } from "./src/modules/events/event.module.js";

let running = false;

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
}, 30000);