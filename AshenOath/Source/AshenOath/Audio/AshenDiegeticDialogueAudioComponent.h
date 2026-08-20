// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticDialogueAudioComponent.generated.h"

/**
 * UAshenDiegeticDialogueAudioComponent
 * Audio component triggering 3D spatialized voice lines for Garrett and Serafina.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticDialogueAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticDialogueAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlaySpatializedVoiceLine(FName CompanionID, FString LineID);
};
