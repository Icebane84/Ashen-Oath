// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenIntegrationMindscapePortalActor.h"

AAshenIntegrationMindscapePortalActor::AAshenIntegrationMindscapePortalActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsPortalOpen = false;
}
void AAshenIntegrationMindscapePortalActor::BeginPlay() { Super::BeginPlay(); }

void AAshenIntegrationMindscapePortalActor::OpenForcedIntegrationPortal()
{
	bIsPortalOpen = true;
	UE_LOG(LogTemp, Error, TEXT("AAshenIntegrationMindscapePortalActor: 100 PERCENT INTEGRATION DEBT REACHED! FORCED MINDSCAPE TRIAL COMMENCED!"));
}
