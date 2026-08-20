// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenGloomwoodTripwireActor.generated.h"

/**
 * AAshenGloomwoodTripwireActor
 * 3D mechanical trap actor spanning a physical wire across 400uu, snapping on contact to trip enemies and interrupt casting bars.
 */
UCLASS()
class ASHENOATH_API AAshenGloomwoodTripwireActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenGloomwoodTripwireActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Trap")
	float TripwireLength = 400.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Trap")
	bool bIsArmed = true;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Trap")
	bool TriggerTripwire(AActor* TargetActor);
};
