import express from "express";

// import eventRoute from "../modules/events/event.module.js";
import { router as eventRoute } from "../modules/events/event.module.js";

const router = express.Router();

router.get("/", (req, res) => {
    res.send("SmartBox backend running");
});

router.get("/health", (req, res) => {
    res.json({ status: "ok" });
});

router.use("/events", eventRoute);

export default router;