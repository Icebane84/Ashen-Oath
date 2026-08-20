// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenGhostbloomFlareComponent.generated.h"

/**
 * UAshenGhostbloomFlareComponent
 * Evaluates high-frequency luminescent flash detonation, applying a 4.0s stun to lesser enemies in a 600uu blast radius.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGhostbloomFlareComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenGhostbloomFlareComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Alchemy")
	float StunDurationSeconds = 4.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Alchemy")
	float FlashRadiusUnits = 600.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Alchemy")
	bool DetonateFlashFlare(FVector DetonationLocation);
};
