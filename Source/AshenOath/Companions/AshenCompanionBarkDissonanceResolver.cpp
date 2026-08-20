// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenCompanionBarkDissonanceResolver.h"

UAshenCompanionBarkDissonanceResolver::UAshenCompanionBarkDissonanceResolver()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FName UAshenCompanionBarkDissonanceResolver::ResolveDominantBark(FName GarrettBark, FName SerafinaBark, float GarrettTrust, float SerafinaTrust)
{
	FName DominantBark = (GarrettTrust >= SerafinaTrust) ? GarrettBark : SerafinaBark;
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionBarkDissonanceResolver: Resolved dominant dialogue bark '%s'"), *DominantBark.ToString());
	return DominantBark;
}
