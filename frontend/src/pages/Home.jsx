import EventList from "../components/eventList.jsx";
import Notification from "../components/Notification.jsx";
import { useLatestNewEvent } from "../hook/useLatestNewEvent.js";

export default function Home() {
  const { event, error } = useLatestNewEvent();

  return (
    <>
      <Notification event={event} error={error} />
      <EventList />;
    </>
  );
}
