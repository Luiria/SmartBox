export default function eventController(service) {

    async function getLatest(req, res) {

        try {

            const event = await service.getLatestEvent();

            res.json(event);

        } catch (error) {

            console.error("[EventController] getLatest failed:", error.message);

            if (error.message === "ADAFRUIT_API_FAILED") {
                return res.status(503).json({
                    error: "External service unavailable"
                });
            }

            return res.status(500).json({
                error: "Internal server error"
            });
        }
    }

    return {
        getLatest,
    };
}   