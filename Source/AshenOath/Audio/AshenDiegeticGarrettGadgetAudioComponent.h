// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticGarrettGadgetAudioComponent.generated.h"

/**
 * UAshenDiegeticGarrettGadgetAudioComponent
 * Audio component playing pneumatic spring clicks, cable tension whirs, and smoke canister hisses.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticGarrettGadgetAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticGarrettGadgetAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayGrappleFireSound();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayTripwireArmSound();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlaySmokeHissSound();
};
