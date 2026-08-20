// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenConsecratedSanctuaryRingActor.generated.h"

/**
 * AAshenConsecratedSanctuaryRingActor
 * In-world glowing golden ward circle actor providing sanctuary.
 */
UCLASS()
class ASHENOATH_API AAshenConsecratedSanctuaryRingActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenConsecratedSanctuaryRingActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Sanctuary")
	float Duration = 12.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Sanctuary")
	void DissolveSanctuaryRing();
};
