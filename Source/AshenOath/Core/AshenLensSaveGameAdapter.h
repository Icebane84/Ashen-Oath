// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSoulConstellationTypes.h"
#include "AshenLensSaveGameAdapter.generated.h"

/**
 * UAshenLensSaveGameAdapter
 * Serializes active EInterpretiveLens and history of chosen lenses across integration cycles to save game.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenLensSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenLensSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SaveActiveLensState(EInterpretiveLens Lens);
};
