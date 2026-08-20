// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenStormBeaconSpireActor.generated.h"

/**
 * AAshenStormBeaconSpireActor
 * World lightning attractor spire channeling psychic storm energy into defensive kinetic shields in regional zones.
 */
UCLASS()
class ASHENOATH_API AAshenStormBeaconSpireActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenStormBeaconSpireActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Weather")
	float AttractionRadius = 1800.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Weather")
	bool bIsSpireHarmonized = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Weather")
	bool HarmonizeSpire(AActor* InstigatingPlayer);
};
