// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenConsciousnessResonanceAltarActor.generated.h"

/**
 * AAshenConsciousnessResonanceAltarActor
 * Rest site altar allowing the player to test multi-channel audio speaker calibration and verify accessibility subtitle profiles.
 */
UCLASS()
class ASHENOATH_API AAshenConsciousnessResonanceAltarActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenConsciousnessResonanceAltarActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Altar")
	bool bIsCalibrated = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Altar")
	void CalibrateAudioChannels(AActor* InstigatingPlayer);
};
