import express from "express";

export default function eventRoutes(controller) {

    const router = express.Router();

    router.get("/sync", controller.sync);

    return router;
}


