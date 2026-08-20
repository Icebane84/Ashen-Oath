// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenSilentSpireMemoryEchoActor.generated.h"

/**
 * AAshenSilentSpireMemoryEchoActor
 * 3D world memory echo actor rendering the collapsed masonry, Garrett's crushed leg trauma, and Kaelen's dark surge at the Silent Spire.
 */
UCLASS()
class ASHENOATH_API AAshenSilentSpireMemoryEchoActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenSilentSpireMemoryEchoActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | World")
	bool bIsEchoReconstructed = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | World")
	void TriggerSpireMemoryEcho();
};
