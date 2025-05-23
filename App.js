// Author: Ruben Rehal

import React from 'react';
import { Provider } from 'react-redux';
import store from './redux/store';
import Tracker from './components/Tracker';

function App() {
  return (
    <Provider store={store}>
      <div style={{ padding: 20 }}>
        <h1>Calorify</h1>
        <Tracker />
      </div>
    </Provider>
  );
}

export default App;
