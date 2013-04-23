#include <stdio.h>
#include <stdlib.h>
#include <libvirt/libvirt.h>
int main(int argc, char *argv[])
{
    virConnectPtr conn;
    virDomainPtr vdp;
    int i=-1;
	int choice;	
    char *host;
    conn = virConnectOpen("xen:///");
    if (conn == NULL) {
        fprintf(stderr, "Failed to open connection to xen:///\n");
        return 1;
    }
	printf("1.suspend\n2.resume\n3.stop\n4.start\n4.exit");
	scanf("%d",&choice);
	
	while(1)
	{
		vdp=virDomainLookupById(conn,1);
	
		if(choice==1)
		{
			/* suspend*/	    
			i=virDomainSuspend(vdp);
			if(i==0)
			{
				printf("Success");
			}else{
				printf("Failed");	
			}
		}
		else if(choice==2)
		{
			/*resume*/
			i=virDomainResume(vdp);
			if(i==0)
			{
				printf("Success");
			}else{
				printf("Failed");	
			}
		}
		else if(choice==3)
		{
			/*shutdown*/
			i=virDomainDestroy(vdp);
			if(i==0)
			{
				printf("Success");
			}else{
				printf("Failed");	
			}
		}
		else if(choice==4)
		{
			/*start*/
			i=virDomainCreate(vdp);
			if(i==0)
			{
				printf("Success");
			}else{
				printf("Failed");	
			}
		}
		else if(choice==5)
		{
			virConnectClose(conn);
			break;
		}
	}	
    return 0;
}
