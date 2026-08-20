// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSomaticTraumaImprintCompiler.generated.h"

/**
 * UAshenSomaticTraumaImprintCompiler
 * Soul component converting physical damage spikes & near-death experiences into permanent somatic imprints.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticTraumaImprintCompiler : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSomaticTraumaImprintCompiler();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Soul")
	int32 TotalSomaticImprintsCompiled = 0;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul")
	void RecordSomaticTraumaEvent(float DamageSeverity, FName BodyPartTag);
};
