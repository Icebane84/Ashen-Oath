// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOath_ManifestationComponent.generated.h"

/**
 * UAshenOath_ManifestationComponent
 * Ports the Godot ManifestationSystem responsible for the unreliable narrator system.
 * Dynamically scales screen distortion and rolls random psychological manifestations based on Sanity.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOath_ManifestationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOath_ManifestationComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Update manifestation timers, distortion lerp, and triggers. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Manifestation")
	void UpdateManifestation(float DeltaTime, float Instability);

	/** Calculate manifestation roll trigger interval based on instability rating. */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Manifestation")
	float GetInterval(float Instability) const;

	/** Trigger a psychological manifestation event. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Manifestation")
	void TriggerManifestation(float Instability);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Manifestation")
	float GetCurrentDistortion() const { return CurrentDistortion; }

	UFUNCTION(BlueprintPure, Category = "AshenOath|Manifestation")
	bool GetActiveInputDelay() const { return bActiveInputDelay; }

private:
	UPROPERTY(VisibleAnywhere, Category = "Manifestation State")
	float Timer;

	UPROPERTY(VisibleAnywhere, Category = "Manifestation State")
	bool bActiveInputDelay;

	UPROPERTY(VisibleAnywhere, Category = "Manifestation State")
	float CurrentDistortion;
};
