// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenThreatPerceptionProducer.generated.h"

/**
 * UAshenThreatPerceptionProducer
 * AI component producing multi-target threat table perception values safely across party targets (Kaelen, Garrett, Serafina).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenThreatPerceptionProducer : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenThreatPerceptionProducer();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Threat")
	float HighestThreatScore = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Threat")
	AActor* ResolvePrimaryThreatTarget();
};
