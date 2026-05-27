export default function eventController(service) {

    async function sync(req, res) {

        try {

            await service.syncEvent();

            return res.status(200).json({
                success: true,
                message: "Events synced successfully"
            });

        } catch (error) {

            console.error("[EventController] sync failed:", error.message);

            if (error.message === "ADAFRUIT_API_FAILED") {
                return res.status(503).json({
                    success: false,
                    error: "External service unavailable"
                });
            }

            return res.status(500).json({
                success: false,
                error: "Internal server error"
            });
        }
    }

    return {
        sync
    };
}   