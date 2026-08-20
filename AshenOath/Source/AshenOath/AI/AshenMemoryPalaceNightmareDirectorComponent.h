// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenMemoryPalaceNightmareDirectorComponent.generated.h"

/**
 * UAshenMemoryPalaceNightmareDirectorComponent
 * AI director managing nightmare phantom shade ambush rates based on local locus trauma density (>0.60).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMemoryPalaceNightmareDirectorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenMemoryPalaceNightmareDirectorComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | AI")
	float NightmareSpawnThreshold = 0.60f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	bool ShouldSpawnNightmareShade(float LocalTraumaDensity) const;
};
