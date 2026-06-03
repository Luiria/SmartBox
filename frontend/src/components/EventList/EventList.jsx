import { useAllEvents } from "../../hook/useAllEvents.js";
import Event from "../Event/Event.jsx";

import "./EventList.module.css";

export default function EventList() {
  const { events, loading, error, refetch } = useAllEvents();

  if (loading) return <p>Loading...</p>;
  if (error) return <p>{error}</p>;
  if (events.length === 0) return <p>No events yet</p>;

  return (
    <>
      <div>
        <button onClick={refetch} disabled={loading}>
          Refresh
        </button>
      </div>

      <ul>
        {events.map((event) => (
          <li key={event.id}>
            <Event event={event} />
          </li>
        ))}
      </ul>
    </>
  );
}
