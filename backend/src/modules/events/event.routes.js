import express from "express";

export default function eventRoutes(controller) {

    const router = express.Router();

    // ! POST OU GET ?
    router.get("/sync", controller.sync);
    router.get("/new", controller.getNewEvent)
    return router;
}


