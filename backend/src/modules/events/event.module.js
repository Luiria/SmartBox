import AdafruitClient from "../../infra/adafruitClient.js";

import eventRoutes from "./event.routes.js";
import eventController from "./event.controller.js";
import EventService from "./event.service.js";

const client = new AdafruitClient();
const service = new EventService(client);
const controller = eventController(service);

const router = eventRoutes(controller);

export default router;