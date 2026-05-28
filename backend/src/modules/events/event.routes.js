import express from "express";

export default function eventRoutes(controller) {

    const router = express.Router();

    router.post("/sync", controller.sync);
    router.get("/new", controller.getNewEvent)
    return router;
}


