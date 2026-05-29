import EventList from "../components/EventList/EventList.jsx";
import Notification from "../components/Notification/Notification.jsx";
import { useLatestNewEvent } from "../hook/useLatestNewEvent.js";

export default function Home() {
  const { notifications } = useLatestNewEvent();
  console.log(notifications);

  return (
    <>
      <Notification notifications={notifications} />
      <EventList />
    </>
  );
}
