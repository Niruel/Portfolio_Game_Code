using System.Collections;
using UnityEngine;
using UnityEngine.UI;


public class GO : MonoBehaviour
{   
    public GameObject spawnObject,
                      endObject, 
                      goPrefab;
 
    private Vector3 spawnPos = new Vector3();
    private Vector3 endPos = new Vector3();
    public Slider speedSlider;
    
    // Use this for initialization
    void Start()
    {

        
        goPrefab.transform.localScale = new Vector3(1, 1, 1);
        spawnPos = spawnObject.transform.position;
        endPos = endObject.transform.position;
        InvokeRepeating("StartSpawn", 0f, 2f);
        SpeedUpdate(SpeedManager.instance.speed);
       
        if (speedSlider)
        {
            SpeedManager.instance.speed = PlayerPrefs.GetFloat("curSpeed");
            speedSlider.value = SpeedManager.instance.speed;
            
        }
        
        
    }

    public void SpeedUpdate(float lineSpeed)
    {
       
        CancelInvoke();
        SpeedManager.instance.speed = lineSpeed;
        PlayerPrefs.SetFloat("curSpeed", SpeedManager.instance.speed);
        SpeedManager.instance.guyList.Clear();
        GameObject[] deleteGuy=GameObject.FindGameObjectsWithTag("Player");

       

        #region


        for (int i = 0; i < deleteGuy.Length; i++)
        {
            Destroy(deleteGuy[i]);
        }


                if (SpeedManager.instance.speed == 1f)
                {
                    InvokeRepeating("StartSpawn", 0f, 2.1f);
                }
                if (SpeedManager.instance.speed == 2f)
                {
                    InvokeRepeating("StartSpawn", 0f, 1f);
                }
                if (SpeedManager.instance.speed == 3f)
                {
                    InvokeRepeating("StartSpawn", 0f, .7f);
                }
                if (SpeedManager.instance.speed == 4f)
                {
                    InvokeRepeating("StartSpawn", 0f, .5f);
                }
                if (SpeedManager.instance.speed == 5f)
                {
                    InvokeRepeating("StartSpawn", 0f, .4f);
                }
                if (SpeedManager.instance.speed == 6f)
                {
                    InvokeRepeating("StartSpawn", 0f, .3f);
                }
                if (SpeedManager.instance.speed == 7f)
                {
                    InvokeRepeating("StartSpawn", 0f, .3f);
                }
                if (SpeedManager.instance.speed == 8f)
                {
                    InvokeRepeating("StartSpawn", 0f, .25f);
                }
                if (SpeedManager.instance.speed == 9f)
                {
                    InvokeRepeating("StartSpawn", 0f, .21f);
                }
                if (SpeedManager.instance.speed == 10f)
                {
                    InvokeRepeating("StartSpawn", 0f, .2f);
                }

            #endregion
        
    }
    public void StartSpawn()
    {
            StartCoroutine(SpawnGuy(SpeedManager.instance.speed));   
    }
  
    IEnumerator startSpawn(float initTime, float interval)
    {
        yield return new WaitForSeconds(initTime);
        while (true)
        {
            yield return new WaitForSeconds(interval);
            yield return SpawnGuy(SpeedManager.instance.speed);
        }

    }
    IEnumerator SpawnGuy(float speed)
    {
        GameObject obj = Instantiate(goPrefab, spawnPos, Quaternion.identity);
        SpeedManager.instance.guyList.Add(obj);
        
        yield return new WaitUntil(() =>
        {
            if (obj != null)
              
            obj.transform.position = Vector3.MoveTowards(obj.transform.position, endPos, speed * Time.deltaTime);
            
            return (obj == null || Vector3.Distance(obj.transform.position, endPos) < 0.1f);
        });
       
        if (obj != null)
        {
            Destroy(obj);
            SpeedManager.instance.guyList.Remove(obj);
        }
    }
}


