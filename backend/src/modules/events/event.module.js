import AdafruitClient from "../../infra/adafruitClient.js";
import { db } from "../../config/db.js";

import eventRoutes from "./event.routes.js";
import eventController from "./event.controller.js";
import EventService from "./event.service.js";
import EventRepository from "./event.repository.js";

const client = new AdafruitClient();
const repository = new EventRepository(db);

const service = new EventService(client, repository);
const controller = eventController(service);

const router = eventRoutes(controller);

// export default router;
export {
    service,
    controller,
    router
};