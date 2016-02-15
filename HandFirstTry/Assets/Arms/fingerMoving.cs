using UnityEngine;
using System.Collections;
using System.IO.Ports;

public class fingerMoving : MonoBehaviour {


	public string data;
	SerialPort sp = new SerialPort("COM4", 9600);

	// Use this for initialization
	void Start () {
	
		sp.Open ();
		sp.ReadTimeout = 1;
	}
	
	// Update is called once per frame
	void Update () {

		data = sp.ReadLine();

		if(sp.IsOpen)
		{
			try
			{
				data = sp.ReadLine();
				Console.Log(data);
				//moveObject(sp.ReadByte());
				//print(sp.ReadByte());
			}

			catch(System.Exception)
			{

			}
		}
        
	}

	void moveObject(int orientation){
		{}
	}
}

