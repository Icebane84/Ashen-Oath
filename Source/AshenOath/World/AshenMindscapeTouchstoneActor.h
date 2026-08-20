// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenMindscapeTouchstoneActor.generated.h"

/**
 * AAshenMindscapeTouchstoneActor
 * Interactive world touchstone actor enabling player resting, memory introspection, and node weaving.
 */
UCLASS()
class ASHENOATH_API AAshenMindscapeTouchstoneActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenMindscapeTouchstoneActor();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Sanctuary")
	bool bTouchstoneActive = true;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Sanctuary")
	bool InitiateTouchstoneIntrospection(AActor* InstigatorCharacter);
};
