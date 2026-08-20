// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCartographicTypes.h"
#include "AshenCartographerAIDirectorComponent.generated.h"

/**
 * UAshenCartographerAIDirectorComponent
 * AI Director commanding companions to point out unmapped vantage points and alchemical harvest groves.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCartographerAIDirectorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCartographerAIDirectorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	void NotifyNearbyUnmappedLandmark(FVector LandmarkLocation, FString LandmarkName);
};
