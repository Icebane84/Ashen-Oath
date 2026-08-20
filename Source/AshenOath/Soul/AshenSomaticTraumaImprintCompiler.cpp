// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Soul/AshenSomaticTraumaImprintCompiler.h"

UAshenSomaticTraumaImprintCompiler::UAshenSomaticTraumaImprintCompiler()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSomaticTraumaImprintCompiler::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSomaticTraumaImprintCompiler::RecordSomaticTraumaEvent(float DamageSeverity, FName BodyPartTag)
{
	TotalSomaticImprintsCompiled++;
	UE_LOG(LogTemp, Log, TEXT("UAshenSomaticTraumaImprintCompiler: Compiled somatic trauma imprint for %s (Severity: %f). Total imprints: %d"), *BodyPartTag.ToString(), DamageSeverity, TotalSomaticImprintsCompiled);
}
