// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LuaState.h"
#include "LuaValue.h"
#include "LuaComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LUAMACHINE_API ULuaComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULuaComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ULuaState> LuaState;


	UFUNCTION(BlueprintCallable, meta = (AutoCreateRefTerm = "Args"))
	FLuaValue LuaCallFunction(FString Function, TArray<FLuaValue> Args);
	
};
