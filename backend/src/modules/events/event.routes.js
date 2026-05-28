import express from "express";

export default function eventRoutes(controller) {

    const router = express.Router();

    router.get("/", controller.getAllEvents)
    router.post("/sync", controller.sync);
    router.get("/latest", controller.getNewEvent)
    return router;
}


