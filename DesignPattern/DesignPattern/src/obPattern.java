import java.io.*;
import java.util.ArrayList;


import org.omg.CORBA.PRIVATE_MEMBER;
import org.omg.CORBA.PUBLIC_MEMBER;
import org.omg.CORBA.SystemException;

public class obPattern {
	
	public interface Observer {
		
		public void update(float temp);
	}
	
	public interface Subject {
		public void registerObserver(Observer o);
		public void removeObserver(Observer o);
		public void notifyObservers();
	}
	
	public interface DisplayElement {
		public void display();
	}
	
	public static class WeatherData implements Subject {
		private float temp;
		private ArrayList observers;
		
		public WeatherData() {
			observers = new ArrayList();
		}
		
		public void registerObserver(Observer o) {
			observers.add(o);
		}
		
		public void removeObserver(Observer o) {
			int i = observers.indexOf(o);
			if ( i > 0) {
				observers.remove(i);
			}
		}
		
		public void notifyObservers() {
			for (int i = 0; i < observers.size(); i++) {
				Observer observer = (Observer)observers.get(i); // get the ith observer and change to Observer interface
				observer.update(temp);
			}
		}
		
		public void measurementsChanged(){
			notifyObservers();
			
		}
		
		public void setMeasurements(float temp) {
			this.temp = temp;
			measurementsChanged();
		}
	}
	
	public static class CurrentConditionsDisplay implements Observer, DisplayElement {
		private float temp;
		private Subject weatherData;
		
		public CurrentConditionsDisplay (Subject weatherData) {
			this.weatherData = weatherData;
			weatherData.registerObserver(this);
		}
		
		public void update(float temp) {
			this.temp = temp;
			display();
		}
		
		public void display() {
				System.out.println("Current conditions:" + temp);
			
		}
	}
	/*
	public static void main (String[] args) {
		WeatherData weatherData = new WeatherData();
		
		CurrentConditionsDisplay currentConditionsDisplay = new CurrentConditionsDisplay(weatherData);
		
		weatherData.setMeasurements(80);
		weatherData.setMeasurements(30.1f);
		weatherData.setMeasurements(40.0f);
	}
	*/
}
