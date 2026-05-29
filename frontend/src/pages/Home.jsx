import EventList from "../components/EventList/EventList.jsx";
import Footer from "../components/Footer/Footer.jsx";
import Header from "../components/Header/Header.jsx";
import Notification from "../components/Notification/Notification.jsx";
import { useLatestNewEvent } from "../hook/useLatestNewEvent.js";

import styles from "./Home.jsx";

export default function Home() {
  const { notifications } = useLatestNewEvent();

  return (
    <div className={styles.home}>
      <Header />
      <Notification notifications={notifications} />
      
      <main className={styles.main}>
        <EventList />
      </main>
      <Footer />
    </div>
  );
}
