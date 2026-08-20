// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenGhostbloomTripwireAnchorActor.generated.h"

/**
 * AAshenGhostbloomTripwireAnchorActor
 * 3D world tripwire anchor spanning between two points, detonating a Ghostbloom flare when crossed by enemy pathing.
 */
UCLASS()
class ASHENOATH_API AAshenGhostbloomTripwireAnchorActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenGhostbloomTripwireAnchorActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Alchemy")
	bool bIsTripwireArmed = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Alchemy")
	void ArmTripwire();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Alchemy")
	void TriggerTripwire();
};
