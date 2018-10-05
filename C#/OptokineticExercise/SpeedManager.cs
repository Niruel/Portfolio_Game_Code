using System.Collections.Generic;
using UnityEngine;




public class SpeedManager : MonoBehaviour {

    public static SpeedManager instance;
    public List<GameObject> guyList;
   

   
    public float speed;
   // public Slider slider;

    void Awake()
    {
        speed = PlayerPrefs.GetFloat("curSpeed");
        if (instance==null)
        {
            DontDestroyOnLoad(gameObject);
            
            instance = this;
            
            guyList = new List<GameObject>();
          
           
        }
        else if(instance !=this)
        {
           
            Destroy(gameObject);
            
        }   
    }
}
