import { useEffect, useState } from "react";
import { fetchLatestNewsEvent } from "../api/event.api";

export function useLatestNewEvent() {

    const [event, setEvent] = useState(null);
    const [error, setError] = useState(null);

    useEffect(() => {
        async function load() {

            try {
                const data = await fetchLatestNewsEvent();
                setEvent(data);
            } catch (err) {
                console.error("[useLatestNewEvent]", err);
                setError(import.meta.env.VITE_ERROR_MESSAGE);
            } 
        }
        load();

        const interval = setInterval(load, 5000);
        return () => clearInterval(interval);
    }, []);

    return { event, error };
}