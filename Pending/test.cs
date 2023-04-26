using System;

public class HelloWorld{
    public static void Main(string[] args){
        var str = "https://test-sampson-private.obs.ap-southeast-3.myhuaweicloud.com/GetPresignedUploadUrl Expired FailToUpload .txt?AccessKeyId=0CJNBYL8MM20QBL4R2TI&Expires=3362915822&Signature=4JrYDYRrvCLiiHS1oPnS1uWvIMM%3D";
        var startIndex = str.IndexOf("Expires=") + "Expires=".Length;
        Console.WriteLine(startIndex);
        var endIndex = str.IndexOf('&', startIndex);
        Console.WriteLine("a");
        Console. WriteLine(endIndex);
        Console.WriteLine (str.Substring(startIndex, endIndex-startIndex)) ;
    }
}

