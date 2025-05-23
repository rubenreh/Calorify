// Author: Ruben Rehal

import React, { useState } from 'react';
import { useDispatch, useSelector } from 'react-redux';
import { addFood, resetLog } from '../redux/calorieSlice';

const Tracker = () => {
  const dispatch = useDispatch();
  const totalCalories = useSelector(state => state.calorie.totalCalories);
  const foodLog = useSelector(state => state.calorie.foodLog);
  const [food, setFood] = useState('');
  const [calories, setCalories] = useState('');

  const handleAdd = () => {
    dispatch(addFood({ food, calories: parseInt(calories) }));
    setFood('');
    setCalories('');
  };

  return (
    <div>
      <input value={food} onChange={(e) => setFood(e.target.value)} placeholder="Food" />
      <input value={calories} onChange={(e) => setCalories(e.target.value)} placeholder="Calories" />
      <button onClick={handleAdd}>Add</button>
      <button onClick={() => dispatch(resetLog())}>Reset</button>
      <p>Total: {totalCalories} kcal</p>
      <ul>
        {foodLog.map((entry, i) => (
          <li key={i}>{entry.food}: {entry.calories} kcal</li>
        ))}
      </ul>
    </div>
  );
};

export default Tracker;
