using UnityEngine;
using System.Collections;
using System.IO.Ports;


public class Mouvements : MonoBehaviour
{

    public string PortToUse = "COM4";

    SerialPort sp = new SerialPort("COM7", 115200);
    public string data;

    public float doigt1;
	public float doigt2;
	public float doigt3;
	public float doigt4;
	public float doigt5;

	public float AX;
	public float AY;
	public float AZ;
	public float GX;
	public float GY;
	public float GZ;

	private float OffsetAX, OffsetAY, OffsetAZ;
	private float OffsetGX, OffsetGY, OffsetGZ; 

	public GameObject Cube;
	public GameObject Camera;
	public GameObject Bras;

	public GameObject D11;
	public GameObject D12;
	public GameObject D13;

	public GameObject D21;
	public GameObject D22;
	public GameObject D23;

	public GameObject D31;
	public GameObject D32;
	public GameObject D33;

	public GameObject D41;
	public GameObject D42;
	public GameObject D43;
    
    void Start()
    {
		try
		{
			sp.Open();
			sp.ReadTimeout = 15;
		}
		catch (System.Exception)
		{
			Debug.Log ("Impossible d'ouvrir le port COM4");
		}
		OffsetAX = 0;
		OffsetAY = 0;
		OffsetAZ = 0;
    }

    // Update is called once per frame
    void Update()
    {
		if (Input.GetKeyDown(KeyCode.I)) {
			InitialisationGyro ();
		}

        if (sp.IsOpen)
        {
			

            try
            {
				data = sp.ReadLine();
				

				doigt1 = (data[1] - '0') + ((data[3] - '0') * 0.1f) + ((data[4] - '0') * 0.01f);
				doigt2 = (data[7] - '0') + ((data[9] - '0') * 0.1f) + ((data[10] - '0') * 0.01f);
				doigt3 = (data[13] - '0') + ((data[15] - '0')*0.1f) + ((data[16] - '0') * 0.01f);
				doigt4 = (data[19] - '0') + ((data[21] - '0')*0.1f) + ((data[22] - '0') * 0.01f);

				AX = ((data[27] - '0')*10000) + ((data[28] - '0') * 1000) + ((data[29] - '0') * 100) + ((data[30] - '0') * 10) + ((data[31] - '0'));
				AX = ((data[26]) == '-') ? -AX : AX;
				AX = (((AX + 16000) * 360) / 32000); 

				AY = ((data[37] - '0')*10000) + ((data[38] - '0') * 1000) + ((data[39] - '0') * 100) + ((data[40] - '0') * 10) + ((data[41] - '0'));
				AY = ((data[36]) == '-') ? -AY : AY;
				AY = (((AY + 16000) * 360) / 32000);

				AZ = ((data[47] - '0')*10000) + ((data[48] - '0') * 1000) + ((data[49] - '0') * 100) + ((data[50] - '0') * 10) + ((data[51] - '0'));
				AZ = ((data[46]) == '-') ? -AZ : AZ;
				AZ = (((AZ + 16000) * 180) / 32000);
				//Debug.Log ("Offset AX : " + OffsetAX + " AY : " + OffsetAY + " AZ : " + OffsetAZ);
				//Debug.Log ("Result AX : " + (AX - OffsetAX) + " AY : " + (AZ - OffsetAZ) + " AZ : " + (AZ - OffsetAZ));

				//Debug.Log(Parent.transform.eulerAngles);

				GX = ((data[57] - '0') * 10000) + ((data[58] - '0') * 1000) + ((data[59] - '0') * 100) + ((data[60] - '0') * 10) + ((data[61] - '0'));
				GX = ((data[56]) == '-') ? -GX : GX;

				GY = ((data[67] - '0') * 10000) + ((data[68] - '0') * 1000) + ((data[69] - '0') * 100) + ((data[70] - '0') * 10) + ((data[71] - '0'));
				GY = ((data[66]) == '-') ? GY : -GY;

				GZ = ((data[77] - '0') * 10000) + ((data[78] - '0') * 1000) + ((data[79] - '0') * 100) + ((data[80] - '0') * 10) + ((data[81] - '0'));
				GZ = ((data[76]) == '-') ? -GZ : GZ;
				MoveObject(AX - OffsetAX - 70, AY - OffsetAY - 30, GZ - OffsetGZ, Cube);
				MoveCamera(GZ - OffsetGZ, Camera);
				MoveBras(GX - OffsetGX, GY - OffsetGY, Bras);

				MoveD(doigt4, D11, D12, D13);
				MoveD(doigt3, D21, D22, D23);
				MoveD(doigt2, D31, D32, D33);
				MoveD(doigt1, D41, D42, D43);
            }
            catch (System.Exception)
            {
				Debug.Log ("Impossible de lire la liaison série");
            }
        }
    }

	void MoveD(float valueD, GameObject D, GameObject D1, GameObject D2)
	{
		D.transform.localEulerAngles = new Vector3(0, -valueD * 50f + 125f, 0);
		D1.transform.localEulerAngles = new Vector3(0, -valueD * 50f + 100f, 0);
		D2.transform.localEulerAngles = new Vector3(0, -valueD * 50f + 100f, 0);

	}

	void MoveObject(float valueX, float valueY, float valueZ, GameObject ObjectToMove)
    {
		ObjectToMove.transform.localEulerAngles = new Vector3 ((valueX * 0.6f) - 90, valueY * 0.6f, ObjectToMove.transform.localEulerAngles.z - 180);
		ObjectToMove.transform.Rotate(new Vector3 (0, 0, -valueZ / 1000f));
		//ObjectToMove.transform.localEulerAngles = new Vector3 (0, 0, valueZ * 0.1f + 90);
    }

	void MoveCamera(float valueY, GameObject CameraToMove) {
		//Debug.Log("GX : " + (GX / 1000f) +  "GY : " + (GY / 1000f) + "GZ : " + (GZ / 1000f));
		CameraToMove.transform.Rotate(new Vector3(0, -(valueY / 1000f), 0)) ; 
	}

	void MoveBras(float valueX, float valueY, GameObject BrasToMove) {
		//Debug.Log("GX : " + (GX / 1000f) +  "GY : " + (GY / 1000f) + "GZ : " + (GZ / 1000f));
		//BrasToMove.transform.Rotate(new Vector3(valueX / 3000f, 0, 0)) ;
		//if (BrasToMove.transform.localPosition.y + (valueY / 8000f) > 0.08f) {
			//BrasToMove.transform.localPosition = new Vector3(0, -0.08f, 0);
		//} else if (BrasToMove.transform.localPosition.y - (valueY / 8000f) < -0.38f) {
			//BrasToMove.transform.localPosition = new Vector3(0, -0.38f, 0);
		//} else {
			//BrasToMove.transform.localPosition += new Vector3(0, 0, valueY / 8000f);
		//}

	}

	void InitialisationGyro()
	{
		try
		{
			
			data = sp.ReadLine();
			AX = ((data[27] - '0')*10000) + ((data[28] - '0') * 1000) + ((data[29] - '0') * 100) + ((data[30] - '0') * 10) + ((data[31] - '0'));
			AX = ((data[26]) == '-') ? -AX : AX;
			OffsetAX = (((AX + 16000) * 360) / 32000) + 90;

			AY = ((data[37] - '0')*10000) + ((data[38] - '0') * 1000) + ((data[39] - '0') * 100) + ((data[40] - '0') * 10) + ((data[41] - '0'));
			AY = ((data[36]) == '-') ? -AY : AY ;
			OffsetAY = (((AY + 16000) * 360) / 32000);

			AZ = ((data[47] - '0')*10000) + ((data[48] - '0') * 1000) + ((data[49] - '0') * 100) + ((data[50] - '0') * 10) + ((data[51] - '0'));
			AZ = ((data[46]) == '-') ? -AZ : AZ;
			OffsetAZ = (((AZ + 16000) * 360) / 32000);

			//MoveObject(OffsetAX, OffsetAY, OffsetAZ, Cube);

			GX = ((data[57] - '0')*10000) + ((data[58] - '0') * 1000) + ((data[59] - '0') * 100) + ((data[60] - '0') * 10) + ((data[61] - '0'));
			OffsetGX = (data[56] == '-') ? -GX : GX;

			GY = ((data[67] - '0')*10000) + ((data[68] - '0') * 1000) + ((data[69] - '0') * 100) + ((data[70] - '0') * 10) + ((data[71] - '0'));
			OffsetGY = (data[66] == '-') ? GY : -GY;

			GZ = ((data[77] - '0')*10000) + ((data[78] - '0') * 1000) + ((data[79] - '0') * 100) + ((data[80] - '0') * 10) + ((data[81] - '0'));
			OffsetGZ = (data[76] == '-') ? -GZ : GZ;

			Debug.Log ("Initialisation... Offset AX : " + OffsetAX + " AY : " + OffsetAY + " AZ : " + OffsetAZ);
		}
		catch (System.Exception)
		{
			Debug.Log ("Impossible de lire la liaison série");
		}
	}

}
