import { useEffect, useState } from "react";
import { fetchAllEvents } from "../api/event.api.js";

export function useAllEvents() {
    const [events, setEvents] = useState([]);
    const [loading, setLoading] = useState(true);
    const [error, setError] = useState(null);

    async function fetchEvents() {
        try {
            setLoading(true);

            const data = await fetchAllEvents();

            setEvents(data);
            setError(null);

        } catch (err) {
            console.error("[useAllEvents]", err);
            setError("Failed to load events");
        } finally {
            setLoading(false);
        }
    }

    useEffect(() => {
        async function load() {
            fetchEvents();
        }
        load();

    }, []);

    return {
        events,
        loading,
        error,
        refetch: fetchEvents
    };

}