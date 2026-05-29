import EventList from "../components/eventList.jsx";
import Notification from "../components/Notification.jsx";
import { useLatestNewEvent } from "../hook/useLatestNewEvent.js";

export default function Home() {
  const { notifications } = useLatestNewEvent();
  console.log(notifications);

  return (
    <>
      <Notification notifications={notifications}  />
      <EventList />;
    </>
  );
}
