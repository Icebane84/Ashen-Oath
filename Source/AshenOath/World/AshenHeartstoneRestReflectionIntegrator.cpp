// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenHeartstoneRestReflectionIntegrator.h"

UAshenHeartstoneRestReflectionIntegrator::UAshenHeartstoneRestReflectionIntegrator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenHeartstoneRestReflectionIntegrator::PublishReflectionState(const FSoulStateVector& Vector)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenHeartstoneRestReflectionIntegrator: Campfire rest reflection published new soul state vector."));
}
