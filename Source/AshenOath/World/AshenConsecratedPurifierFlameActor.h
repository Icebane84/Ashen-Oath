// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenConsecratedPurifierFlameActor.generated.h"

/**
 * AAshenConsecratedPurifierFlameActor
 * In-world ground fire hazard spawned by purifier claymore strikes dealing burning tick damage.
 */
UCLASS()
class ASHENOATH_API AAshenConsecratedPurifierFlameActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenConsecratedPurifierFlameActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Purifier Hazard")
	float FireRadius = 250.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Purifier Hazard")
	float BurnDuration = 4.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Purifier Hazard")
	void ExtinguishFlameHazard();
};
